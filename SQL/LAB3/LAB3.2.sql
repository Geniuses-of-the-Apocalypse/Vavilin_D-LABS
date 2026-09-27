USE lab3;

-- ( 1 )
SELECT
	s.SURNAME,
    e.EXAM_ID
FROM
	student s
INNER JOIN
	exam_marks e ON s.STUDENT_ID = e.student_STUDENT_ID;
    
-- ( 2 )
SELECT 
    s.SURNAME, 
    u.RATING, 
    u.CITY
FROM 
    student s
LEFT JOIN 
    university u ON s.university_UNIV_ID = u.UNIV_ID
ORDER BY 
    s.SURNAME ASC;

-- (3)
SELECT 
    s.SURNAME, 
    sub.SUBJ_NAME, 
    e.MARK
FROM 
    exam_marks e
JOIN 
    student s ON e.student_STUDENT_ID = s.STUDENT_ID
JOIN 
    subjects sub ON e.subjects_SUBJ_ID = sub.SUBJ_ID
WHERE 
    e.MARK IN (4, 5);
    
-- ( 4 )
SELECT
	s1.SURNAME AS Student1,
    s2.SURNAME AS Student2
FROM
	student s1
JOIN 
	student s2 ON s1.CITY = s2.CITY
WHERE
	s1.STUDENT_ID < s2.STUDENT_ID;
