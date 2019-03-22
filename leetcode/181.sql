SELECT Emp.Name AS 'Employee'
FROM (SELECT * FROM Employee) AS Emp
    INNER JOIN (SELECT * FROM Employee) AS Mng
        ON Emp.ManagerId = Mng.Id
WHERE Emp.Salary > Mng.Salary;
