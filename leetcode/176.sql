SELECT (SELECT Salary AS SecondHighestSalary
FROM Employee
WHERE Salary NOT IN (
    SELECT Salary
    FROM Employee
    WHERE Salary >= ALL(SELECT Salary FROM Employee))
ORDER BY Salary DESC
LIMIT 0, 1) AS SecondHighestSalary;
