USE lab2;

-- ( 1 )
SELECT COUNT(*) AS Total_Students
FROM Student;

-- ( 2 )
SELECT 
	Subject,
    COUNT(*) AS Count_Marks
FROM
	Matks
GROUP BY
	Subject;
    
-- ( 3 )
SELECT
	Subject,
    AVG(Mark) AS Average_Mark
FROM
	Matks
GROUP BY
	Subject;

-- ( 4 )
SELECT MAX(Mark) AS Max_Mark
FROM Matks;

-- ( 5 )
SELECT COUNT(*) AS Students_With_Multiple_A
FROM Student
WHERE (LENGTH(Surname) - LENGTH(REPLACE(Surname, 'a', ''))) > 1;
