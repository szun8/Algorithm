-- 코드를 입력하세요
SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.NAME
from ANIMAL_INS right outer join ANIMAL_OUTS on ANIMAL_INS.ANIMAL_ID =  ANIMAL_OUTS.ANIMAL_ID
where ANIMAL_INS.datetime is NULL
order by animal_id