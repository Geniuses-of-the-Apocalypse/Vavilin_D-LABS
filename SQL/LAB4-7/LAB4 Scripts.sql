USE lab3;

-- (1)
SELECT DISTINCT s.SUBJ_NAME
FROM subjects s
JOIN exam_marks em ON s.SUBJ_ID = em.subjects_SUBJ_ID
WHERE em.MARK > ALL (
	SELECT MARK
    FROM exam_marks
    WHERE subjects_SUBJ_ID = 105
);

-- (2)
SELECT s.SUBJ_NAME, COUNT(em.EXAM_ID) AS mark_count
FROM subjects s
JOIN exam_marks em ON s.SUBJ_ID = em.subjects_SUBJ_ID
GROUP BY s.SUBJ_ID, s.SUBJ_NAME
HAVING COUNT(em.EXAM_ID) = (
    SELECT MIN(cnt) 
    FROM (
        SELECT COUNT(EXAM_ID) AS cnt
        FROM exam_marks
        GROUP BY subjects_SUBJ_ID
    ) AS min_counts
);

-- (3)
SELECT u1.UNIV_NAME AS University_1, u2.UNIV_NAME AS University_2
FROM university u1
JOIN university u2 ON u1.CITY = u2.CITY
WHERE u1.UNIV_ID < u2.UNIV_ID;

-- (4)
SELECT STUDENT_ID, NAME
FROM student s1
WHERE STIPEND = (
	SELECT MAX(STIPEND)
    FROM student s2
    WHERE s2.CITY = s1.CITY
);

-- (5)
SELECT STUDENT_ID, NAME
FROM student
WHERE CITY NOT IN (
	SELECT CITY
    FROM university
);