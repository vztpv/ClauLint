# ClauLint - ToDo!
  Validator ( for EU4 SaveGame Data Style? Text, and ClauText? )

# Example?

    character = { 
      %type = object* # %type? $type$?
      %option = make_from_data # ? 

      %from = { 
        %name = { %type = integer_id %option = chk_range %value = { 0 1024 } } # UserType Name

        이름 = { %type = string %option = chk_from_file %from = { "이름.txt" } }
        성별 = { %type = string %option = chk_from_list %from = { "남자" "여자" } }
        종족 = { %type = integer_id %option = chk_from_file %from = { "종족.txt" } }
        이명? = { %type = string* %option = chk_from_file %from = { "이명.txt" } } # optional?
        직업? = { %type = integer_id* %option = chk_from_file %from = { "직업.txt" } } # optional?
        소속? = { %type = integer_id* %option = chk_from_file %from = { "소속.txt" } } # optional?
      }
    }
  
# Example - Valid Text?
    character = {
      0 = { 
        이름 = abc
        성별 = 남자
        종족 = 0
        소속 = { 0 1 2 }
      }
      1 = {
        이름 = def
        성별 = 여자
        종족 = 0 
        직업 = { 0 }
      }
    }
