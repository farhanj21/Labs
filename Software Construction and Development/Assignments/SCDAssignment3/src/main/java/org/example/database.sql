CREATE DATABASE Assignment3;
use Assignment3;
-- Create Resources table
CREATE TABLE Resources (
                           personID INT PRIMARY KEY AUTO_INCREMENT,
                           name VARCHAR(255) NOT NULL
);

-- Create ResourceSkills table
CREATE TABLE ResourceSkills (
                                personID INT,
                                skill VARCHAR(255) NOT NULL,
                                level VARCHAR(50),
                                FOREIGN KEY (personID) REFERENCES Resources(personID)
);


-- Create Tasks table
CREATE TABLE Tasks (
                       taskID INT PRIMARY KEY AUTO_INCREMENT,
                       name VARCHAR(255) NOT NULL
);

-- Create TaskSkills table
CREATE TABLE TaskSkills (
                            taskID INT,
                            skill VARCHAR(255) NOT NULL,
                            level VARCHAR(50),
                            FOREIGN KEY (taskID) REFERENCES Tasks(taskID)
);

-- Inserting Resources
INSERT INTO Resources (personID, name) VALUES (1, 'Ahmed');
INSERT INTO Resources (personID, name) VALUES (2, 'Ayesha');
INSERT INTO Resources (personID, name) VALUES (3, 'Ali');
INSERT INTO Resources (personID, name) VALUES (4, 'Sara');
INSERT INTO Resources (personID, name) VALUES (5, 'Salman');

-- Inserting ResourceSkills
-- Ahmed's Skills
INSERT INTO ResourceSkills (personID, skill, level) VALUES (1, 'c', '2');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (1, 'c++', '3');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (1, 'java', '1');

-- Ayesha's Skills
INSERT INTO ResourceSkills (personID, skill, level) VALUES (2, 'c', '2');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (2, 'c++', '2');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (2, 'assembly', '2');

-- Ali's Skills
INSERT INTO ResourceSkills (personID, skill, level) VALUES (3, 'c++', '3');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (3, 'java', '3');

-- Sara's Skills
INSERT INTO ResourceSkills (personID, skill, level) VALUES (4, 'java', '4');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (4, 'javascript', '2');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (4, 'python', '1');

-- Salman's Skills
INSERT INTO ResourceSkills (personID, skill, level) VALUES (5, 'python', '3');
INSERT INTO ResourceSkills (personID, skill, level) VALUES (5, 'javascript', '2');
-- Inserting Tasks (Resources)
INSERT INTO Tasks (taskID, name) VALUES (1, 'Web Development');
INSERT INTO Tasks (taskID, name) VALUES (2, 'Data Analytics');
INSERT INTO Tasks (taskID, name) VALUES (3, 'System Programming');


-- Inserting TaskSkills
-- Web Development's Required Skills
INSERT INTO TaskSkills (taskID, skill, level) VALUES (1, 'javascript', 'e');
INSERT INTO TaskSkills (taskID, skill, level) VALUES (1, 'java', 'i');

-- Data Analytics's Required Skills
INSERT INTO TaskSkills (taskID, skill, level) VALUES (2, 'python', 'e');
INSERT INTO TaskSkills (taskID, skill, level) VALUES (2, 'javascript', 'i');

-- System Programming's Required Skills
INSERT INTO TaskSkills (taskID, skill, level) VALUES (3, 'c', 'i');
INSERT INTO TaskSkills (taskID, skill, level) VALUES (3, 'c++', 'i');
INSERT INTO TaskSkills (taskID, skill, level) VALUES (3, 'assembly', 'i');

