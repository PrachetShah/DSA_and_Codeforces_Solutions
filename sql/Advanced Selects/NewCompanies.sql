SELECT c.company_code,
    c.founder,
    COUNT(DISTINCT l.lead_manager_code) as total_lead_managers,
    COUNT(DISTINCT s.senior_manager_code) as total_senior_managers,
    COUNT(DISTINCT m.manager_code) as total_managers,
    COUNT(DISTINCT e.employee_code) as total_employees
FROM Company c
LEFT JOIN Lead_Manager l ON c.company_code=l.company_code
LEFT JOIN Senior_Manager s ON c.company_code=s.company_code
LEFT JOIN Manager m ON c.company_code=m.company_code
LEFT JOIN Employee e ON c.company_code=e.company_code
GROUP BY c.company_code, c.founder
ORDER BY c.company_code;