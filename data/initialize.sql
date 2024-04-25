create table students
(
    id int primary key,
    first_name text,
    last_name text,
    born_year int,
    is_active int,
    credits_earned int,
    residency int
);

create table courses
(
    id int primary key,
    course_name text,
    semester_id int, 
    credits int default 0
);

create table course_student
(
    course_id int,
    student_id int,
    primary key (course_id, student_id),
    foreign key(course_id) references course(id),
    foreign key(student_id) references student(id)
);

insert into students
(
    id,
    first_name,
    last_name,
    born_year,
    is_active,
    credits_earned,
    residency
)
values
(21, 'James', 'Kirk', 1976, 1, 10, 1),
(22, 'Jean-Luc', 'Picard', 1976, 1, 100, 1),
(23, 'Benjamin', 'Sisko', 1976, 1, 99, 1),
(24, 'Kathryn', 'Janeway', 1974, 1, 99, 1),
(25, 'Han', 'Solo', 1974, 1, 99, 1),
(26, 'Jeron', 'Andor', 1974, 1, 99, 1),
(27, 'Ahsoka', 'Tano', 1974, 1, 99, 1),
(28, 'Admiral', 'Akbar', 1974, 1, 99, 1);

insert into courses
(
    id,
    course_name,
    semester_id,
    credits
)
values
(1, 'CTCH 1330', 20237, 3),
(2, 'MATH 2302', 20237, 4);

insert into course_student
(
    course_id,
    student_id
)
values
(1, 23),
(1, 24),
(2, 21),
(2, 22),
(2, 23),
(2, 24),
(2, 25),
(2, 26),
(2, 27),
(2, 28);