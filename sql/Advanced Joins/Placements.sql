-- Method 1 - using simple joins
SELECT s.name
FROM Students s
JOIN Friends f ON s.id=f.id 
JOIN Packages p1 ON s.id=p1.id
JOIN Packages p2 ON f.friend_id=p2.id
WHERE p2.salary > p1.salary
ORDER BY p2.salary

-- Using cte
WITH StudentSalary AS (
    SELECT s.ID, s.Name, p.Salary
    FROM Students s
    JOIN Packages p ON s.ID = p.ID
),
FriendSalary AS (
    SELECT f.ID, p.Salary AS FriendSalary
    FROM Friends f
    JOIN Packages p ON f.Friend_ID = p.ID
)
SELECT ss.Name
FROM StudentSalary ss
JOIN FriendSalary fs ON ss.ID = fs.ID
WHERE fs.FriendSalary > ss.Salary
ORDER BY fs.FriendSalary;