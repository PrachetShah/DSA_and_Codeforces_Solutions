-- Method 1
SELECT SALARY*MONTHS AS EARNINGS, COUNT(*)
FROM EMPLOYEE
GROUP BY EARNINGS
ORDER BY EARNINGS DESC
LIMIT 1;

-- method 2
select max(salary*months), count(*) from Employee where salary*months = ( select max(salary*months) from employee)