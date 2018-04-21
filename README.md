# ClauLint
    Validator and Schema Maker? ( for EU4 SaveGame Data Style? Text, and ClauText? ),
    Using VisualStudio2017, Windows10, ClauText header files.

# Example?
 # in data check file?
    # %int %float %string %dateA,B,C?
    # %optional %any
    # %one_more  <>  %just_one
    # %id %total_id

    ## cf) NO_USE_INPUT? - default is false? or true?

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

        # USE_BOOL4_FUNC -> default?
        # NO USE_BOOL4_FUNC -> start ^ # ex) ^/./row only return /./row ?

        # todo!
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

    provinces = { # $가 안 붙으면 파일 체크 데이터?
        %int%id%one_more = {
            # Comparison between UserType and UserType?
            pos%total_id%event_pos_test = { row = %int col = %int } 
            country = %string
            tax = %int%event_test
        }
    }

    countries = {
        %string%id = {
            # x = { 1 2 3 4  } -> x = { %int%one_more%event_is_plus }
            provinces = { %total_id%one_more%event_test } 
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

