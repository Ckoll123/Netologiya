CREATE TABLE employee(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50),
    department VARCHAR(50),
    boss_id INTEGER REFERENCES employee(id)
);