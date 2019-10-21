vector<short> thumb_vec;
vector<short> index_vec;
vector<short> middle_vec;
vector<short> ring_vec;
vector<short> pinky_vec;
bool startRelease = false;
bool startGrasp = false;
bool startDeform = false;

static void deform(void* arg) 
{
  while (1) 
  {
    sensor s;
    xQueueReceive(sensor_Queue, &s, portMAX_DELAY);
    short tt_pot = mean_filter_pot(thumb_vec , s.tt_pot);
    short i_pot = mean_filter_pot(index_vec , s.i_pot);
    short m_pot = mean_filter_pot(middle_vec , s.m_pot);
    short r_pot = mean_filter_pot(ring_vec , s.r_pot);
    short p_pot = mean_filter_pot(pinky_vec , s.p_pot);
    //Serial.println(s.i_pot);
    //Serial.println(s.m_pot);
    //------------------------------grasp---------------------------
    if(startGrasp)
    {
      //start deformation calculation 
      if(startDeform)
      {
      }
      //------------move index--------------
      if(i_pot < i_MAX)
      {
        set_index_speed(i_GRASP, 30);
      }
      else
      {
        set_index_speed(i_GRASP, 0);
      }
      //-----------move middle-------------
      if(m_pot < m_MAX)
      {
        set_middle_speed(m_GRASP, 30);
      }
      else
      {
        set_middle_speed(m_GRASP, 0);
      }
    }
    
    else if(startRelease)
    {
      //------------move index--------------
      if(i_pot < i_MIN)
      {
        set_index_speed(i_RELEASE, 0);
      }
      else
      {
        set_index_speed(i_RELEASE, 30);
      }
      //-----------move middle-------------
      if(m_pot < m_MIN)
      {
        set_middle_speed(m_RELEASE, 0);
      }
      else
      {
        set_middle_speed(m_RELEASE, 30);
      }
    }
    else 
    {
    }
  }
}

//*******warning this function can be faster*************/
int mean_filter_pot( vector<short> &vec ,short adc)
{
   //filter for pot
    vec.push_back(adc);
    int number = vec.size();
    if(number == 51)
    {
      vec.erase(vec.begin());
    }
    int sum = 0;
    for(int i=0; i< number; i++)
    {
      sum = sum + vec[i];
    }
    return sum/(10*number);
}

//-----------------api of motor control------------------
void start_grasp_with_deform()
{
  startGrasp = true;
  startRelease = false;
  startDeform = true;
}

void start_grasp()
{
  startGrasp = true;
  startRelease = false;
}

void start_replase()
{
  startGrasp = false;
  startRelease = true;
}
