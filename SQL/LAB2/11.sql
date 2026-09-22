USE lab2;
SELECT DISTINCT Surname
FROM Student S
JOIN Matks M ON idStudent = Student_idStudent
WHERE Subject = 'Math' AND Mark >= 3;