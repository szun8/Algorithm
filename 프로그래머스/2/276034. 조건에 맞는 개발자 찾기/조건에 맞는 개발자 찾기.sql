select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS
where SKILL_CODE & (select sum(CODE) from SKILLCODES where NAME = 'C#' or NAME = 'Python') != 0
order by ID