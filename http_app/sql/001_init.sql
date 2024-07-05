
CREATE TABLE AppUser(
    id INTEGER PRIMARY_KEY,
    username VARCHAR UNQIUE,
    email VARCHAR UNQIUE,
    password VARCHAR,
    role VARCHAR,
);
INSERT INTO AppUser
(usernmae, email, password, role) VALUES('admin', 'admin@domain.com', 'admin', 'ROLE_ADMIN');
