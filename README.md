# ClauLint
    Validator and Schema Maker? ( for EU4 SaveGame Data Style? Text, and ClauText? ),
    Using VisualStudio2017, Windows10, ClauText header files.

# Example?
 # in data check file?
    # %int %float %string %dateA,B,C?
    # %optional %any
    # %one_more  <>  %just_one
    # %id %total_id
    # %required 


    $ZERO = 0 # for Event? # define -> $~, USE -> ~

    $Event = { # $Event?, %event_test
        id = test
        $parameter = { input }

        $return = { $COMP>EQ = { $parameter.input /./ZERO } }
    }

    $Event = { # %event_pos_test
        id = pos_test
        $parameter = { input }  # 3 4    $add = { 3 4 }
        $local = { row col }


        $assign_from_ut = { $local.row data = { $parameter.input } dir = { /./row } }
        $assign_from_ut = { $local.col data = { $parameter.input } dir = { /./col } }

        $if = { 
            cond = { $AND_ALL = { $COMP>EQ = { $local.row 0 } $COMP>EQ = { $local.col 0 } 
                                $COMP<EQ = { $local.row 1 } $COMP<EQ = { $local.col 1 } } 
            }
            then = {
                $return = { TRUE }
            }
        }

        # FALSE or ERROR?
        $print = { err_msg = { "row, col is not valid" } }
        $print = { enter = { \n } }
        $return = { FALSE }
    }

    provinces%required = { # $가 안 붙으면 파일 체크 데이터?
        %int%required%id%one_more = {
            # Comparison between UserType and UserType?
            pos%required%total_id%event_pos_test = { row = %int col = %int } 
            country%required = %string
            tax%required = %int%event_test
        }
    }

    countries%required = {
        %string%required%id%one_more = {
            # x = { 1 2 3 4  } -> x = { %int%one_more%event_is_plus }
            provinces%required = { %required%total_id%one_more%event_test } 
            # %total_id => it is id(unique value) in /./countries/$/provinces ( $ means all ) 
            core%one_more = %total_id%int%event_test
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
        USA = {
            provinces = { 0 1 }
            core = 0
            core = 1
        }
    }

