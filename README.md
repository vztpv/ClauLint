# ClauLint - ToDo!
    Validator and Make Schema? ( for EU4 SaveGame Data Style? Text, and ClauText? ),
    Using VisualStudio2017, Windows10, ClauText.h

# Example?
    ## ClauLint?
    # in data check file?
    Event = {
        id = test
        $parameter = { input }
        
        $return = { $COMP>EQ = { $parameter.input 0 } } # input >= 0
    }
    provinces = {
        %int%id = {
            pos = { row = %int col = %int } # cf) pos%id ?
            country = %string
            tax = %event_test
        }
    }

    # in data file?
    provinces = {
        0 = {
            pos = { row = 0 col = 0 }
            country = USA
            tax = 10
        }
        1 = {
            pos = { row = 0 col = 1 }
            country = USA
            tax = 20
        }
    }

    countries = {
        0 = { 
            name = USA
            provinces = { 0 1 }
        }
    }
