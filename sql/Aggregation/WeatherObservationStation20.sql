WITH cte AS (
    SELECT LAT_N,
        ROW_NUMBER() OVER (ORDER BY LAT_N) as rn,
        COUNT(*) OVER () as total_rows
    FROM STATION
)
SELECT ROUND(AVG(cte.LAT_N), 4) 
FROM cte 
WHERE rn IN ( (total_rows + 1) / 2, (total_rows + 2) / 2 );

-- ✅ Explanation
-- ROW_NUMBER() OVER (ORDER BY LAT_N) → gives sequential numbers (1, 2, 3 …).
-- COUNT(*) OVER () → gives total row count in every row.
-- Middle positions:
    -- (total+1)/2 → middle if odd, left-middle if even
    -- (total+2)/2 → middle if odd (same as above), right-middle if even
-- Filter only those rows → then AVG(LAT_N) gives correct median.
-- ROUND(...,4) → 4 decimal places.

-- If sorted LAT_N = [10, 15, 20, 25, 30] (total=5)
--     Positions = (6/2, 7/2) = (3,3) → pick 3rd = 20 → median=20.0000

-- If sorted LAT_N = [10, 15, 20, 25] (total=4)
--     Positions = (5/2, 6/2) = (2,3) → pick rows 15 and 20 → avg=17.5000