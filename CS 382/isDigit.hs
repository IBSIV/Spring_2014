isDigit :: Char -> Bool

isDigit a = a>='0' && a <= '9'

abs :: Int -> Int

abs n= if n>=0 then n 
       else -n