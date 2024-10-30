-- 코드를 입력하세요
SELECT HISTORY_ID, CAR_ID
    , date_format(START_DATE , "%Y-%m-%d") as START_DATE
    , date_format(end_DATE , "%Y-%m-%d") as END_DATE
    , if(DATEDIFF(END_DATE, START_DATE) >= 29, '장기 대여', '단기 대여') as RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
where date_format(START_DATE , "%Y-%m") like '2022-09'
order by HISTORY_ID	desc