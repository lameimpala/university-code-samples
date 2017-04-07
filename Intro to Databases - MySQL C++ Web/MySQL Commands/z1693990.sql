#Name: Reid Wixom
#Class: CSCI 466 - Section 1
#Due: 3/11/16



#1.drop/delete all of the tables/views you will be creating below
SET FOREIGN_KEY_CHECKS=0;
drop table if exists dogs;
drop table if exists visits;
drop view if exists NumberVisits;
SET FOREIGN_KEY_CHECKS=1;

#2.Create a table dogs with a dog id, a breed and a name. 
#Dog id should be an auto-increment primary key.
CREATE TABLE dogs
(dog_id INT AUTO_INCREMENT,
breed CHAR(20),
name CHAR(20),
PRIMARY KEY(dog_id));

#3. Put at least 5 records in this table.
INSERT INTO dogs (breed, name) VALUES('german shepard', 'sandy');
INSERT INTO dogs (breed, name) VALUES('poodle', 'daisy');
INSERT INTO dogs (breed, name) VALUES('daschund', 'dino');
INSERT INTO dogs (breed, name) VALUES('saint bernard', 'smokey');
INSERT INTO dogs (breed, name) VALUES('labrador', 'moxi');

#4. Do a select * on this table to show all the records
SELECT * from dogs;

#5.Create a table called visits with a visit id (auto-
#increment primary key), dog id (foreign key into dogs) and
#date. Use the CURDATE() function.
CREATE TABLE visits
(
visit_id INT AUTO_INCREMENT,
dog_id INT,
visit_date DATE,
PRIMARY KEY(visit_id),
FOREIGN KEY (dog_id) REFERENCES dogs(dog_id)
);

#6. Put at least 8 records in this table
INSERT INTO visits (dog_id, visit_date) VALUES(1, CURDATE());
INSERT INTO visits (dog_id, visit_date) VALUES(2, CURDATE());
INSERT INTO visits (dog_id, visit_date) VALUES(3, CURDATE());
INSERT INTO visits (dog_id, visit_date) VALUES(4, CURDATE());
INSERT INTO visits (dog_id, visit_date) VALUES(5, CURDATE());
INSERT INTO visits (dog_id, visit_date) VALUES(3, '2015-01-23');
INSERT INTO visits (dog_id, visit_date) VALUES(2, '2015-03-01');
INSERT INTO visits (dog_id, visit_date) VALUES(1, '2016-02-01');

#7. Do a select * on this table to show all the records
SELECT * FROM visits;

#8. Add a column to the visit table for the time or day of week
#– there are many date/time functions, pick one to use.
ALTER TABLE visits
ADD weekday CHAR(10);

#9.Update several rows to add values to the column you just
#created.
INSERT INTO visits (dog_id, visit_date, weekday) VALUES(1, '2016-02-01', DAYOFWEEK('2016-02-01'));
INSERT INTO visits (dog_id, visit_date, weekday) VALUES(5, '2016-02-08', DAYOFWEEK('2016-02-08'));
INSERT INTO visits (dog_id, visit_date, weekday) VALUES(3, '2016-03-09', DAYOFWEEK('2016-03-09'));

#10. Do a select * on this table to show all the records
SELECT * FROM visits;

#11. Define a view that will list each dog and the number of
#visits they have made.
CREATE VIEW NumberVisits AS
SELECT dog.name AS Dogs, count(visit.dog_id) AS Visits
FROM visits visit, dogs dog
WHERE dog.dog_id = visit.dog_id
GROUP BY dog.dog_id;

#12. Do a select * on this view to show all the records
SELECT * FROM NumberVisits;
