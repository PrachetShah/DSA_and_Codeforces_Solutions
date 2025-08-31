SELECT 
    one.X, 
    one.Y
FROM Functions one
INNER JOIN Functions two
    ON one.X=two.Y AND one.Y=two.X
GROUP BY one.X, one.Y
HAVING COUNT(one.X)>1 OR one.X < one.Y
ORDER BY one.X ASC