USE Lab3;

-- (1)
SELECT UNIV_NAME, CITY
FROM university
WHERE RATING >= (
	SELECT RATING
    FROM university
    WHERE UNIV_NAME = 'GUU'
);

-- (2)
SELECT s.NAME
FROM student s 
JOIN exam_marks em ON s.STUDENT_ID = em.student_STUDENT_ID
WHERE em.subjects_SUBJ_ID = 10 AND em.MARK > (
	SELECT AVG(MARK)
    FROM exam_marks
);

-- (3)
SELECT s.NAME
FROM student s 
JOIN exam_marks em ON s.STUDENT_ID = em.student_STUDENT_ID
WHERE em.subjects_SUBJ_ID = 12 AND em.MARK < (
	SELECT AVG(MARK)
    FROM exam_marks
);

-- (4)
SELECT s.STUDENT_ID, s.NAME, COUNT(DISTINCT em.subjects_SUBJ_ID) AS subject_count
FROM student s
JOIN exam_marks em ON s.STUDENT_ID = em.student_STUDENT_ID
GROUP BY s.STUDENT_ID, s.NAME
HAVING COUNT(DISTINCT em.subjects_SUBJ_ID) > 2;

-- (5)
SELECT DISTINCT s.STUDENT_ID, s.NAME
FROM student s 
JOIN exam_marks em ON s.STUDENT_ID = em.student_STUDENT_ID
WHERE em.MARK <= 2 AND s.STUDENT_ID IN (
	SELECT student_STUDENT_ID
    FROM exam_marks
    WHERE MARK > 2
    GROUP BY student_STUDENT_ID
    HAVING AVG(MARK) > 4
);

-- (6)
SELECT STUDENT_ID, NAME 
FROM student s1 
WHERE STIPEND = (
	SELECT MAX(STIPEND)
    FROM student s2
    WHERE s2.CITY = s1.CITY
);

-- (7)
SELECT *
FROM student s 
WHERE EXISTS (
	SELECT 1
    FROM university u 
    WHERE u.CITY = s.CITY AND u.UNIV_ID <> s.university_UNIV_ID
);

-- (8)
SELECT s.SURNAME, sub.SUBJ_NAME
FROM student s 
JOIN exam_marks em ON s.STUDENT_ID = em.student_STUDENT_ID
JOIN subjects sub ON em.subjects_SUBJ_ID = sub.SUBJ_ID;

-- (9)
SELECT s.NAME AS student_name, sub.SUBJ_NAME
FROM student s 
JOIN exam_marks em ON s.STUDENT_ID = em.student_STUDENT_ID
JOIN subjects sub ON em.subjects_SUBJ_ID = sub.SUBJ_ID
WHERE em.MARK IN (4, 5)
ORDER BY s.NAME;

-- (10)
SELECT u.UNIV_NAME, MAX(s.STIPEND) AS max_stipend
FROM university u 
JOIN student s ON u.UNIV_ID = s.university_UNIV_ID
WHERE u.RATING > 4
GROUP BY u.UNIV_ID, u.UNIV_NAME;
