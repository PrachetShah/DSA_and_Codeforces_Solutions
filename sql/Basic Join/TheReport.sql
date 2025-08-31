SELECT 
    CASE 
        WHEN b.Grade>=8 THEN name
        ELSE NULL
    END as Name,
    b.Grade,
    a.Marks
FROM Students a
INNER JOIN Grades b
-- ON a.Marks >= b.Min_Mark AND a.Marks <= b.Max_Mark
ON a.Marks BETWEEN b.Min_Mark AND b.Max_Mark
ORDER BY b.Grade DESC, Name asc, a.Marks asc