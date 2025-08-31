SELECT t.hacker_id, t.name, SUM(t.total_score) AS total_score
FROM (
    SELECT 
        h.hacker_id, 
        h.name, 
        MAX(s.score) AS total_score
    FROM 
        Hackers h
        INNER JOIN Submissions s
            ON h.hacker_id = s.hacker_id
    WHERE 
        s.score != 0
    GROUP BY 
        h.hacker_id, h.name, s.challenge_id
) t
GROUP BY t.hacker_id, t.name
ORDER BY total_score DESC, t.hacker_id;