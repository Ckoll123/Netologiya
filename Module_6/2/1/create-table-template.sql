CREATE TABLE genre(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50)
);
COMMENT ON TABLE genre IS 'Жанр';

CREATE TABLE singer(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50)
);

CREATE TABLE genreSinger(  
    id_genre INTEGER NOT NULL REFERENCES genre(id),
    id_singer INTEGER NOT NULL REFERENCES singer(id),
    CONSTRAINT PK PRIMARY KEY (id_genre, id_singer)
);

CREATE TABLE album(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50),
    year INTEGER
);

CREATE TABLE singerAlbum(  
    id_album INTEGER NOT NULL REFERENCES album(id),
    id_singer INTEGER NOT NULL REFERENCES singer(id),
    CONSTRAINT PK2 PRIMARY KEY (id_album, id_singer)
);

CREATE TABLE track(  
    id SERIAL PRIMARY KEY,
    album_id INTEGER REFERENCES album(id),
    name VARCHAR(50),
    duration INTEGER
);

CREATE TABLE collection(  
    id SERIAL PRIMARY KEY,
    name VARCHAR(50),
    year INTEGER
);


CREATE TABLE trackCollection(  
    id_track INTEGER NOT NULL REFERENCES track(id),
    id_collection INTEGER NOT NULL REFERENCES collection(id),
    PRIMARY KEY (id_track, id_collection)
);