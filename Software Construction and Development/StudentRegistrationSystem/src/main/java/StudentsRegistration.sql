CREATE DATABASE StudentsDB;
USE StudentsDB;
CREATE TABLE students
(
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    student_name VARCHAR(255),
    student_age INT
);

INSERT INTO students (student_id, student_name, student_age) VALUES (1, 'Farhan Jafri', 21);
INSERT INTO students (student_id, student_name, student_age) VALUES (2, 'Haris Maken', 20);
INSERT INTO students (student_id, student_name, student_age) VALUES (3, 'Ali Arfa', 23);
INSERT INTO students (student_id, student_name, student_age) VALUES (4, 'Ammar Hassan', 21);
