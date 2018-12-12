CREATE TABLE estudiante(
id INTEGER PRIMARY KEY AUTOINCREMENT,
nombre TEXT,
num_estudiante INTEGER,
fechaNac DATE,
sexo TEXT,
dpto_menor TEXT,
dpto_principal TEXT,
direccion TEXT,
tele_actual INTEGER,
grado INTEGER
);
CREATE TABLE informe_calificaciones(
id INTEGER PRIMARY KEY AUTOINCREMENT,
id_estudiante REFERENCES estudiante(id),
seccion REFERENCES secciones(num_seccion),
calificacion TEXT,
grado_numerico INTEGER
);
CREATE TABLE cursos(
id INTEGER PRIMARY KEY AUTOINCREMENT,
universidad TEXT,
nombre TEXT,
num_oficina INTEGER
);
CREATE TABLE CursoSeccion(
id_curso REFERENCES cursos(id),
id_seccion REFERENCES secciones(id)
);
CREATE TABLE secciones(
id INTEGER PRIMARY KEY AUTOINCREMENT,
num_seccion INTEGER,
profesor TEXT,
año DATE,
semestre INTEGER
, id_curso REFERENCES cursos(id));
