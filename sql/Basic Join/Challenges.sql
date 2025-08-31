WITH cte AS(
    SELECT c.hacker_id AS id, h.name AS name, count(c.hacker_id) AS counter
    FROM Hackers h
    JOIN Challenges c on c.hacker_id = h.hacker_id
    GROUP BY c.hacker_id, h.name
)
SELECT id, name, counter
FROM cte
WHERE
counter=(SELECT max(counter) FROM cte) /*select user that has max count submission*/
OR
counter IN (SELECT counter FROM cte
GROUP BY counter
HAVING COUNT(counter)=1 ) /*filter out the submission count which is unique*/
ORDER BY counter DESC, id