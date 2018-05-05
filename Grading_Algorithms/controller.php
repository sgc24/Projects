<?php
  
  //Validate user/pass********************************************
  if(isset($_POST['action']) && $_POST['action'] == 'login')
  {
  
    $cred = array(
     "user" => $_REQUEST['user'],
     "pass" => $_REQUEST['pass'],
     "action" => $_REQUEST['action']
    );
    
    echo curl($cred);
  }
  
   //Send Question Credentials to DB******************************
   if(isset($_POST['action']) && $_POST['action'] == 'add_question')
   {
       $question = array(
         "function_name" => $_POST['function_name'],
         "title"         => $_POST['title'],
         "difficulty"    => $_POST['difficulty'],
         "description"   => $_POST['description'],
         "topic"         => $_POST['topic'],
         "test_cases"    => $_POST['test_cases'],
         "input1"       => $_POST['input1'],
         "input2"       => $_POST['input2'],
         "input3"       => $_POST['input3'],
         "input4"       => $_POST['input4'],
         "input5"       => $_POST['input5'],
         "result1"       => $_POST['result1'],
         "result2"       => $_POST['result2'],
         "result3"       => $_POST['result3'],
         "result4"       => $_POST['result4'],
         "result5"       => $_POST['result5'],
         "action"        => $_POST['action']
        );
      
       echo curl($question);
   }
   //retrieve question from db
   if(isset($_POST['action']) && $_POST['action'] == 'get_question')
   {
       $arr = array(
         "action" => $_POST['action'],
         "qid"    => $_POST['qid']
       );
    
    echo curl($arr);
    
   }
   //get list of all questions in qb 
   if(isset($_POST['action']) && $_POST['action'] == 'get_question_list')
   {
        $arr = array(
          "action" => $_POST['action']
        );
        
        echo curl($arr);
    }
    //add question to exam
    if(isset($_POST['action']) && $_POST['action'] == 'add_question_to_exam')
    {
        $arr = array(
          "action"           => $_POST['action'],
          "qid"              => $_POST['qid'],
          "title"            => $_POST['title'],
          "header_score"     => $_POST['header_score'],
          "indent_score"     => $_POST['indent_score'],
          "topic_score"      => $_POST['topic_score'],
          "execution_score"  => $_POST['execution_score'],
          "question_score"   => $_POST['question_score']
         );
       
        echo curl($arr);
        
   }
   
   //get list of questions that will be on exam
   if (isset($_POST['action']) && $_POST['action'] == 'get_exam_question_list')
  {
    $arr = array(
      "action" => $_POST['action']
    );
    
    echo curl($arr);
  }
  //grade score, then send it
  if (isset($_POST['action']) && $_POST['action'] == 'store_student_answer')
  {
    
    $arr = array(
     "action" => 'get_question',
     "qid"    => $_POST['qid']
        );
        
    $points = array(
      "action" => 'exam_point_value',
      "qid"    => $_POST['qid']
      );
      
    $question = json_decode(curl($arr), true);
    $points = json_decode(curl($points), true);
  
    $arr = array(
      "action" => $_POST['action'],
      "user" => $_POST['user'],
      "qid" => $_POST['qid'],
      "answer"      => $_POST['answer']
    );
   
    $arr = grading_time($question, $arr, $points);
    print_r($arr);
    echo curl($arr);
  }
  
  //put code back in text field if student is not done 
  if (isset($_POST['action']) && $_POST['action'] == 'store_student_score')
  {
      $arr = array(
        "action" => 'store_student_answer',
        "user" => $_POST['user'],
        "qid" => $_POST['qid'],
        "answer" => $_POST['answer'],
        "send_db" => $_POST["send_db"]
       );
       
      echo curl($arr); 
  }
  if (isset($_POST['action']) && $_POST['action'] == 'get_student_answer')
  {
    $arr = array(
      "action" => $_POST['action'],
      "user" => $_POST['user'],
      "qid" => $_POST['qid']
    );
      
    echo curl($arr);
  }
  //release the scores
  if (isset($_POST['action']) && $_POST['action'] == 'release_scores')
  {
    $arr = array(
      "action" => $_POST['action']
    );
    
    echo curl($arr);
  }
  //view the scores
  if (isset($_POST['action']) && $_POST['action'] == 'view_scores')
  {
    $arr = array(
      "action" => $_POST['action'],
      "user" => $_POST['user']
    );
      
    echo curl($arr);
    
  }
  //show score and grading citeria to student
  if (isset($_POST['action']) && $_POST['action'] == 'get_student_score')
  {
    $arr = array(
      "action" => $_POST['action'],
      "qid"    => $_POST['qid'],
      "user" => $_POST['user']
     );
      
    echo curl($arr);
  }  
  //filter the questions
  if(isset($_POST['action']) && $_POST['action'] == 'filter_question_list')
  {
    $arr = array(
      "action" => $_POST['action'],
      "filter_other" => $_POST['filter_other'],
      "filter_diff"  => $_POST['filter_diff']
     );
     
     
    
    echo curl($arr);
  
  }
  //remove a question from the exam
  if(isset($_POST['action']) && $_POST['action'] == 'remove_question_from_exam')
  {
      $arr = array(
      "action" => $_POST['action'],
      "qid" => $_POST['qid']
       );
  
      echo curl($arr);
  
  } 
  
  if(isset($_POST['action']) && $_POST['action'] == 'get_question_with_points')
  {
      $arr = array(
      "action" => $_POST['action'],
      "qid" => $_POST['qid']
       );
  
      echo curl($arr);
  
  }
  
  /*++++++++++++++++++++++++++++++++++++++++++
    + This Function curls off to the databse +
    + and returns what the database sent     +
    ++++++++++++++++++++++++++++++++++++++++ +*/
  function curl($arr)
  {
      $ch = curl_init("https://web.njit.edu/~mem52/model.php");//Open up Curl session with database
  
      curl_setopt($ch, CURLOPT_POST, 1);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_POSTFIELDS, $arr);
  
      $output = curl_exec($ch);
      curl_close($ch);
      
      return $output;
  
  }
   
  /*++++++++++++++++++++++++++++++++++++++++++
    + This Function grades each question and +
    + returns an updated array with scores   +
    ++++++++++++++++++++++++++++++++++++++++ +*/ 
  function grading_time($question, $arr, $points)
  {      
      $python  = $_POST['answer'];
      $question_point_value = $points['question_score'];
      $send_db = [];
      
      $h_array = array(
        "item_graded"     => "header",
        "correctness"     => "correct",
        "total_points"    => $question_point_value * .3,
        "acquired_points" => $question_point_value * .3,
        "write_up"        => "",
      );
      
      $e_array = array(
        "item_graded"     => "execution",
        "correctness"     => "correct",
        "total_points"    => $question_point_value * .3,
        "acquired_points" => $question_point_value * .3,
        "write_up"        => "",
      );
      
      $o_array = array(
        "item_graded"     => "Test Cases",
        "correctness"     => "correct",
        "total_points"    => $question_point_value * .4,
        "acquired_points" => $question_point_value * .4,
        "write_up"        => "",
      );
      
      $f_score = array(
        "acquired_points" => 0,
        "total_points"    => $question_point_value
      );
       
      $python_file = 'p.py';
      $pfile = fopen($python_file, 'w');
      $python_test = $_POST['answer'];
      $python_test .= build_function_call($question, 1);
      fwrite($pfile, $python_test);
      $result = shell_exec('python /afs/cad.njit.edu/u/s/g/sgc24/public_html/p.py');
      $flag = 0;
      
      if(!$result)
      {  
         if(!check_header($question, $python, $h_array, $points)) // check header first? if incorrect, correct it and grade the rest
         {
            $h_array["correctness"] = "Incorrect";
            $mod_python = $python;
         }
         
         $pfile = fopen($python_file, 'w');
         $mod_python = $python;
         $mod_python .= build_function_call($question, 1);
         fwrite($pfile, $mod_python);
         fclose($pfile);
         $result = shell_exec('python /afs/cad.njit.edu/u/s/g/sgc24/public_html/p.py');
         
         //check indentation after correcting the function header the program still does not run
         if(!$result)
         { 
           if(!check_indentation($mod_python, $e_array))
           {
             $e_array["acquired_points"] = 0;
             $e_array["correctness"] = "Incorrect";
             $e_array['write_up'] .= " => - " . ($question_point_value * .3) . " points";
           }
           //it has to be a syntax error
           else
           {
             $e_array["acquired_points"] = 0;
             $e_array["write_up"] = "Syntax error in body of code => - " . ($question_point_value * .3);
             $e_array["correctness"] = "Incorrect";
           }
         }
      }
      
      for($i = 1; $i <= $question['test_cases']; $i++)
      {
          $pfile = fopen($python_file, 'w');
          $next_python = $python;
          $next_python.= build_function_call($question, $i);
          fwrite($pfile, $next_python);
          fclose($pfile);
          $result = shell_exec('python /afs/cad.njit.edu/u/s/g/sgc24/public_html/p.py');
          $line = strtok($result, "\r\n");
          //if the code the studuent wrote does not yield the same output as the result from the test cases
          if(strcmp($line, $question['result'. $i]) != 0) 
          {
              $f_name = find_func_name($question['function_name']);
              $o_array['write_up'] .= 'Output is not correct, failed test case: ' . $i . ' => ' . $f_name . '(' . $question['input'.$i] . ')' . ' => -';
              $flag = 0;
              $o_array['correctness'] = "Incorrect";
              
              if($question['test_cases'] == 1)
              {
                  $o_array['write_up'] .= ($question_point_value * .40) . " points\n";
                  $o_array["acquired_points"] = $o_array["acquired_points"] - ($question_point_value * .40);
              }
              
              else if($question['test_cases'] == 2)
              {
                  $o_array['write_up'] .= ($question_point_value * .20) . " points\n";
                  $o_array["acquired_points"] = $o_array["acquired_points"] - ($question_point_value * .20); 
              }
              
              else if($question['test_cases'] == 3)
              {
                  $o_array['write_up'] .=  number_format((float)$o_array["total_points"] / 3, 2, '.', '') . " points\n";
                  $o_array["acquired_points"] = $o_array["acquired_points"] - ($o_array["total_points"] / 3); 
                  
              }
              
              else if($question['test_cases'] == 4)
              {         
                  $o_array['write_up'] .= ($question_point_value  * .10) . " points\n";
                  $o_array["acquired_points"] = $o_array["acquired_points"] - ($question_point_value * .10); 
              }
              
              else if($question['test_cases'] == 5)
              {
                  $o_array['write_up'] .= ($question_point_value  * .08) . " points\n";
                  $o_array["acquired_points"] = $o_array["acquired_points"] - ($question_point_value * .08); 
              }
          }
          
          else // if test case matches the result
          {
              $o_array['write_up'] .= "Output is correct, passed test case: " . $i . "\n";
          }
      $flag = 1;
      }
      //check if they use the keyword print 
      if(!check_wrong_doing($question, $_POST['answer']))
      {
          $e_array["write_up"] .= "Illegal use of keyword, 'print' ";
          $deduction = ($o_array['acquired_points'] + $e_array['acquired_points'] + $h_array['acquired_points']) * .30;
          $deduction = floor($deduction);
          $e_array["write_up"] .= "- " . $deduction . " points\n";
          $e_array['correctness'] = "Incorrect";
          $e_array['acquired_points'] -= $deduction;
      }
      
      $o_array["acquired_points"] = ceil($o_array["acquired_points"]);
        
      if($o_array["acquired_points"] == -0)
      {
          $o_array["acquired_points"] = 0;
      } 
      //add up all the points student got  
      $f_score['acquired_points'] = ($o_array['acquired_points'] + $e_array['acquired_points'] + $h_array['acquired_points']);
      
      
      $send_db = json_encode(array(
        "0" => $h_array,
        "1" => $e_array,
        "2" => $o_array,
        "3" => $f_score
        ));
      
      $arr["send_db"] =  $send_db;
      
      return $arr;
 }   
 
  /* +++++++++++++++++++++++++++++++++++++++++++++++++++++++
    + This Function creates the function call and appends +
    + it to the python code the student wrote             +
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/  
 function build_function_call($question, $i)
 {
   $p ='';
   //Disassemble
   $function_name = preg_replace('/\s+/', '', $question['function_name']); // extract spaces and junk
   $func= "";
   $j = 0; 
   
   //extract function name
   for($j = 0; $j < strlen($function_name); $j++)
  {
      if( $function_name[$j] == "(" )
      {
        break;
      }  
      
      $func .= $function_name[$j];
  }
   
   $parameters = substr($function_name, $j , strlen($function_name) - 1); //gets rid of function name
   
   $num_parameters = substr_count($parameters, ',') + 1; // how many parameters
   $t_cases = $question['input'.$i];
   $t_cases = preg_replace('/\s+/', '', $t_cases);
   $t_cases = preg_split("/[,]+/", $t_cases);
   
   if(is_numeric($t_cases[0]))
   {
     $p .= "\nprint(" . $func . "(" . $t_cases[0];      //build the function call with the test cases
   }
   else
   {
     $p .= "\nprint(" . $func . "(\"" . $t_cases[0] . "\"";
   } 
   if($num_parameters > 1)
   {
      if(is_numeric($t_cases[1]))
      {
        $p .= "," . $t_cases[1];
      }
      else
      {
        $p .= ",\"" . $t_cases[1] . "\"";
      }
      if($num_parameters > 2)
      {
        if(is_numeric($t_cases[2]))
        {
          $p .= "," . $t_cases[2];
        }
        else
        {
          $p .= ",\"" . $t_cases[2] . "\"";
        } 
      }
   }
   $p .= "))";
   
   return $p;
 }
 
 /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    + This Function compares the function header the      +
    + student wrote, and compares it to the correct header+
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/     
 function &check_header($question, &$python, &$h_array, $points)
 {   
    $correct = $question['function_name'];
    $correct .= ":";
    $correct = "def " . $correct;
    
    $correct = preg_replace('/\s+/', '', $correct);
   
    $user = strtok($python, "\r\n");
    $user = preg_replace('/\s+/', '', $user);
   
    if($correct == $user)
    {
      return 1;
    }
     
    else
    {
      if(strcmp(substr($python, 0, 4), "def ") !=  0)//check if they wrote def or not
      {
          $h_array["write_up"] .= "Missing 'def' => - " . ($points['question_score'] * .075) . " points\n";
          $h_array["acquired_points"] = $h_array["acquired_points"] - ($points['question_score'] * .075);
          $python = "def " . $python;
      }
      
      $c_func = find_func_name($question['function_name']);
      $u_func = find_func_name($user);
      
      if($c_func != $u_func)//compare function name
      {
        $h_array["write_up"] .= "Missing or incorrect spelling of: " . $c_func . " => - " . ($points['question_score'] * .075) . " points\n";
        $h_array["acquired_points"] = $h_array["acquired_points"] - ($points['question_score'] * .075);
      }
      
      if(substr($user, strlen($user) -1) != ":")// check for colon at end of function header
      {
        $h_array["write_up"] .= "Missing ':' at the end of the line => - " . ($points['question_score'] * .075) . " points\n";
        $h_array["acquired_points"] = $h_array["acquired_points"] - ($points['question_score'] * .075);
        
      }
      
      $c_param = find_parameters($correct);
      $u_param = find_parameters($user);
      
     
      if($c_param != $u_param)//compare parameter list
      {
        $h_array["write_up"] .= "Function parameters do not match " . $c_param . " => - " . ($points['question_score'] * .075) . " points\n";
        $h_array["acquired_points"] = $h_array["acquired_points"] - ($points['question_score'] * .075);
      }
      
      $c_replace = $question['function_name'];
      $c_replace .= ":";
      $c_replace = "def " . $c_replace;
      $python = str_replace(strtok($python, "\r\n"), $c_replace, $python);
      
      return 0;
    }
 }
 
 /* +++++++++++++++++++++++++
    + This Function checks  +
    + for indentation errors+
    +++++++++++++++++++++++++*/
 function check_indentation($p, &$e_array)
 {
    $line_num = 1;
    $indent = "";
    $line = strtok($p, "\r\n");
    
    while($line)
    {    
        if(substr($line, strlen($line) -1) == ":")
        { 
            $indent = $indent . "     ";
            $line = strtok("\r\n");
            $line_num += 1;
            if($line)
            {
              if(substr($line, 0, strlen($indent)) != $indent)
              {
                  $e_array['write_up'] = "error, incorrect indentation on line: " . $line_num;
                  $e_array['correctness'] = "Incorrect";
                  return 0;
              }
            }
        }
        else
        {
            $indent = "";
            $line=strtok("\r\n");
        }
    }
    
    return 1;
 }
 /* +++++++++++++++++++++++++
    + This Function checks  +
    + if the topic was used +
    +++++++++++++++++++++++++*/
 function check_wrong_doing($question, $python)
 {
    if(strpos($python, "print") == false)//substring search for print if found they in trouble
    {
        return 1;
    }
    
    return 0;
 }
 /* ++++++++++++++++++++++++++++
    + This Function finds the  +
    + function name in header  +
    ++++++++++++++++++++++++++++*/
 function find_func_name($q)
 {
   $function_name = preg_replace('/\s+/', '', $q); // extract spaces and junk
   $function_name = str_replace("def" , "", $function_name);
   $func= "";
   $j = 0;
   
   //extract function name
   for($j = 0; $j < strlen($function_name); $j++)
   {
       if( $function_name[$j] == "(" )
       {
         break;
       }  
       $func .= $function_name[$j];
   }
   return $func;
 }
 /* +++++++++++++++++++++++++++++
    + This Function finds the   +
    + parameter list in header  +
    +++++++++++++++++++++++++++++*/
 function find_parameters($parameters)
 {
   $parameters = preg_replace('/\s+/', '', $parameters); // extract spaces and junk
   $func= "";
   $j = 0;
   
   //extract function name
   for($j = 0; $j < strlen($parameters); $j++)
   {
       if( $parameters[$j] == "(" )
       {
         break;
       }  
       $func .= $parameters[$j];
   }
   
   $p = substr($parameters, $j , strlen($parameters) - 1); //gets rid of function name
   if(substr($p, strlen($p) -1) == ":")
   {
     $p = substr($p, 0, -1); // gets rid of :
   }
   
   return $p;
 } 
 //this function is not currently in use for this project
 function extract_func_call(&$python, $question)
 {
   $p ='';
   $function_name = preg_replace('/\s+/', '', $question['function_name']); // extract spaces and junk
   
   $func= "";
   $j = 0; 
   
   for($j = 0; $j < strlen($function_name); $j++)
  {
      if( $function_name[$j] == "(" )
      {
        break;
      }  
      
      $func .= $function_name[$j];
  }
   
   $parameters = substr($function_name, $j , strlen($function_name) - 1); //gets rid of function name
   $num_parameters = substr_count($parameters, ',') + 1; // how many parameters
   
   
   //Disassemble
   $t_cases = $question['input1'];
   $t_cases = preg_replace('/\s+/', '', $t_cases);
   $t_cases = preg_split("/[,]+/", $t_cases);
  
   if(is_numeric($t_cases[0]))
   {
     $p .= "\nprint(" . $func . "(" . $t_cases[0];      //build the function call with the test cases
   }
   
   else
   {
     $p .= "\nprint(" . $func . "(\"" . $t_cases[0] . "\"";
   } 
   
   if($num_parameters > 1)
   {
      if(is_numeric($t_cases[1]))
      {
        $p .= "," . $t_cases[1];
      }
      
      else
      {
        $p .= ",\"" . $t_cases[1] . "\"";
      }
      
      if($num_parameters > 2)
      {
        if(is_numeric($t_cases[2]))
        {
          $p .= "," . $t_cases[2];
        }
        
        else
        {
          $p .= ",\"" . $t_cases[2] . "\"";
        } 
      }
   }
   
   $p .= "))";
 
   return str_replace($p, "", $python);
 }
 
?>