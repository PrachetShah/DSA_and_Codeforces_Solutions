WITH cte AS (
    SELECT LAT_N,
        ROW_NUMBER() OVER (ORDER BY LAT_N) as rn,
        COUNT(*) OVER () as total_rows
    FROM STATION
)
SELECT ROUND(AVG(cte.LAT_N), 4) 
FROM cte 
WHERE rn IN ( (total_rows + 1) / 2, (total_rows + 2) / 2 );