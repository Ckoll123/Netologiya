SELECT a.name, s.name, COUNT(gs.id_genre)
FROM album a
JOIN singeralbum sa ON a.id = sa.id_album
JOIN singer s ON sa.id_singer = s.id
JOIN genresinger gs ON s.id = gs.id_singer
GROUP BY a.name, s.name
HAVING COUNT(gs.id_genre) > 1;

SELECT t.id, t.album_id, t.name
FROM track t
LEFT JOIN trackcollection tc ON t.id = tc.id_track
WHERE tc.id_collection IS NULL;


SELECT s.name, t.name, t.duration
FROM singer s
JOIN singeralbum sa ON s.id = sa.id_singer
JOIN album a ON sa.id_album = a.id
JOIN track t ON a.id = t.album_id
WHERE t.duration = (SELECT MIN(track.duration) FROM track)ж


SELECT a.name, COUNT(t.id)
FROM album a
JOIN track t ON a.id = t.album_id
GROUP BY a.name
HAVING COUNT(t.id) = (SELECT MIN(track_count)
                            FROM (
                                SELECT COUNT(track.id) AS track_count FROM track
                                JOIN album ON track.album_id = album.id
                                GROUP BY album.id
                            ) AS min_tracks
)
