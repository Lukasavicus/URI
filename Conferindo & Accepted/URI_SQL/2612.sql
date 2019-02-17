--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2612

CREATE TABLE genres (
  id numeric PRIMARY KEY,
  description varchar(50)
);

CREATE TABLE movies (
  id numeric PRIMARY KEY,
  name varchar(50),
  id_genres numeric REFERENCES genres (id)
);

CREATE TABLE actors (
  id numeric PRIMARY KEY,
  name varchar(50)
);

CREATE TABLE movies_actors (
  id_movies numeric REFERENCES movies (id),
  id_actors numeric REFERENCES actors (id)
); 

INSERT INTO genres (id, description)
VALUES
  (1,	'Animation'),
  (2,	'Horror'),
  (3,	'Action'),
  (4,	'Drama'),
  (5,	'Comedy');
  
INSERT INTO movies (id, name, id_genres)
VALUES
  (1,	'Batman',	3),
  (2,	'The Battle of the Dark River',	3),
  (3,	'White duck',	1),
  (4,	'Breaking Barriers',	4),
  (5,	'The Two Hours',	2);
  
INSERT INTO actors (id, name)
VALUES
  (1,	'Brad Antonio'),
  (2,	'Marcelo Silva'),
  (3,	'Miguel Silva'),
  (4,	'Drake Frost'),
  (5,	'Rodrigo Juares Rodriguez');
    
INSERT INTO movies_actors (id_movies, id_actors)
VALUES
  (1,2),
  (2,3),
  (3,2),
  (4,1),
  (5,2);

  /*  Execute this query to drop the tables */
  -- DROP TABLE movies_actors, actors, movies, genres; --

-- ============================================================================

-- Solution 2612

  SELECT m.id, m.name FROM movies as m
    INNER JOIN movies_actors as ma ON m.id = ma.id_movies
    INNER JOIN actors as a ON a.id = ma.id_actors
    INNER JOIN genres as g ON g.id = m.id_genres
    WHERE (g.description = 'Action') AND (a.name = 'Miguel Silva' OR a.name = 'Marcelo Silva');

-- ============================================================================