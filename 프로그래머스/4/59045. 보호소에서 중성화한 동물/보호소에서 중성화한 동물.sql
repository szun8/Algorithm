-- 코드를 입력하세요
SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.ANIMAL_TYPE, ANIMAL_OUTS.NAME
from ANIMAL_INS left outer join ANIMAL_OUTS on ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID
where ANIMAL_INS.SEX_UPON_INTAKE like "Intact%"
        and (ANIMAL_OUTS.SEX_UPON_OUTCOME like "Spayed%"
        or ANIMAL_OUTS.SEX_UPON_OUTCOME like "Neutered%")
order by ANIMAL_INS.ANIMAL_ID