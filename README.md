# ClauLint
  Validator ( for EU4 SaveGame Data Style? Text, and ClauText? )

# Example?

    character = { 
      %type = object* # %type? $type$?
      %option = make_from_data # ? 

      %from = { 
        %name = { %type = integer_id %option = make_range %value = { 0 1024 } } # UserType Name

        이름 = { %type = string %option = make_from_file %from = { "이름.txt" } }
        성별 = { %type = string %option = make_from_list %from = { "남자" "여자" } }
        종족 = { %type = integer_id %option = make_from_file %from = { "종족.txt" } }
        이명 = { %type = string* %option = make_from_file %from = { "이명.txt" } }
        직업 = { %type = integer_id* %option = make_from_file %from = { "직업.txt" } }
        소속 = { %type = integer_id* %option = make_from_file %from = { "소속.txt" } }
      }
    }
  
  
