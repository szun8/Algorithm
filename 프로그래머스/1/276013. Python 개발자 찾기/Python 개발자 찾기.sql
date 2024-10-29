select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPER_INFOS
where skill_1 in ('python') or skill_2 in ('python') or skill_3 in ('python')
order by id