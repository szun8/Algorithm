SELECT board.TITLE,
    board.BOARD_ID,
    reply.REPLY_ID,
    reply.WRITER_ID,
    reply.CONTENTS,
    date_format(reply.CREATED_DATE, "%Y-%m-%d") as CREATED_DATE
from USED_GOODS_BOARD as board
inner join USED_GOODS_REPLY as reply on board.BOARD_ID = reply.BOARD_ID
where YEAR(board.CREATED_DATE) = 2022 and MONTH(board.CREATED_DATE) = 10 
order by reply.CREATED_DATE, board.title