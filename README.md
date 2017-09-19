# ClauLint - ToDo!
    Validator and Make Schema? ( for EU4 SaveGame Data Style? Text, and ClauText? ),
    Using VisualStudio2017, Windows10, ClauText.h

# Example?
        {
            %name = { %type = string %value = character }
            %type = object*
            {
                %name = { %type = integer_id %option = chk_range %value = { 0 1024 } }
                %type = object
                {
                    %name = { %type = string %value = { 이름 } }
                    %type = string
                    %option = chk_from_file 
                    %value = { "이름.txt" }
                }
                {
                    %name = { %type = string %value = { 성별 } }
                    %type = string
                    %option = chk_from_list
                    %value = { 남자 여자 }	
                }
                {
                    %name = { %type = string %value = { 종족 } }
                    %type = integer_id
                    %option = chk_from_file 
                    %value = { "종족.txt" }	
                }
                {
                    %name = { %type = string %value = { 이명 } }
                    %type = string*
                    %option = chk_from_file
                    %optional = true
                    %value = { "이명.txt" }
                }
                {
                    %name = { %type = string %value = { 직업 } }
                    %type = integer_id*
                    %option = chk_from_file
                    %optional = true
                    %value = { "직업.txt" }
                }
                {
                    %name = { %type = string %value = { 소속 } }
                    %type = integer_id*
                    %option = chk_from_file
                    %optional = true
                    %value = { "소속.txt" }
                }
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
