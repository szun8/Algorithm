-- 코드를 입력하세요
SELECT BOOK_ID,AUTHOR_NAME, date_format(PUBLISHED_DATE, "%Y-%m-%d") as PUBLISHED_DATE
from BOOK join AUTHOR on AUTHOR.author_id = book.author_id
where CATEGORY like '경제'
order by PUBLISHED_DATE