SELECT Name AS 'Customers'
FROM Customers AS c
    LEFT JOIN Orders AS o
        ON c.Id = o.CustomerId
WHERE o.CustomerId IS NULL;
