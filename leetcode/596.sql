SELECT class
FROM (SELECT COUNT(DISTINCT student) AS cnt, class
     FROM courses
     GROUP BY class) AS res
WHERE res.cnt >= 5;
