#include "unity.h"
#include "Message.h"
#include "ButtonSM.h"
#include "LedSM.h"
#include "mock_Button.h"

void setUp(void){}

void tearDown(void){}

void test_message_button_pressed_LedState_should_change_to_LED_BLINKING_ON(){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
	buttonInitData(&buttonData);

  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);
  
  isButtonPressed_ExpectAndReturn(1);
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_ON, ledData.state);
}

void test_message_button_release_LedState_should_change_to_LED_OFF(){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
	buttonInitData(&buttonData);

  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);;
  
  isButtonPressed_ExpectAndReturn(0);
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);
}

void test_message_button_presses_once_and_2times_input_LedState_should_present_LED_BLINKING_ON____LED_BLINKING_OFF(){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
	buttonInitData(&buttonData);

  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);
  
  isButtonPressed_ExpectAndReturn(1);
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_ON, ledData.state);
   
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_OFF, ledData.state);
}

void test_message_button_presses_once_and_3times_input_LedState_should_present_LED_BLINKING_ON____LED_BLINKING_OFF___LED_BLINKING_ON(){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
	buttonInitData(&buttonData);

  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);
  
  isButtonPressed_ExpectAndReturn(1);
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_ON, ledData.state);
   
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_OFF, ledData.state);
  
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_ON, ledData.state);
}

void test_message_button_presses_twice_LedState_should_present_LED_BLINKING_ON____LED_ON(){
  LedData ledData;
  ButtonData buttonData;
  printf("test msg line 87\n");
  
  ledInitData(&ledData);
	buttonInitData(&buttonData);

  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);
  
  isButtonPressed_ExpectAndReturn(1);
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_BLINKING_ON, ledData.state);
   
  isButtonPressed_ExpectAndReturn(1);
  buttonInitData(&buttonData);
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_ON, ledData.state);
  
}