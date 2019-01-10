/*
  File: AltoviewMDot.h

  Version: v0.2.4

  Brief: Arduino library for controlling Multitech mDot LoRa modules using
         AT commands.

  Copyright: This library is published under GNU AGPLv3 license.
             http://choosealicense.com/licenses/agpl-3.0/

  Author: Campbell Scientific Australia Pty Ltd
*/

#ifndef ALTOVIEW_MDOT_H
#define ALTOVIEW_MDOT_H

#include "Arduino.h"
#include <AltSoftSerial.h>
#include <avr/pgmspace.h>

#define _DR0_PAYLOAD_USAGE 11     //Use 11 of 11 available bytes in payload
#define _DR1_PAYLOAD_USAGE 53     //Use 53 of 53 available bytes in payload
#define _DR2_PAYLOAD_USAGE 126    //Use 126 of 126 available bytes in payload
#define _DR3_PAYLOAD_USAGE 126    //Use 126 of 242 available bytes in payload
#define _DR4_PAYLOAD_USAGE 126    //Use 126 of 242 available bytes in payload

//    static const uint8_t _MAX_FRAGMENTS = 16;
#define _MAX_FRAGMENTS 10
#define _PACKET_SIZE 11
#define _HEADER_SIZE 2
#define _PAYLOAD_SIZE (_PACKET_SIZE - _HEADER_SIZE)
#define _HEADER_OFFSET 48         //ASCII offest to start at char = '0'

#define _MAX_PAIRS_SIZE 70
#define _MAX_MDOT_RESPONSE 140    //Max number of bytes the mdot might return
#define _MAX_MDOT_COMMAND 60     //TODO: Check against the manual for mDot


/*
  Class definition
*/
class AltoviewMDot
{
  public:
    char networkSessionKey[48] = {'\0'};          //00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00
    char dataSessionKey[48] = {'\0'};             //00.00.00.00.00.00.00.00.00.00.00.00.00.00.00.00
    char networkKey[48] = {'\0'};                 //00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:01
    char networkId[24] = {'\0'};                  //00:00:aa:00:00:00:00:01
    char deviceId[24] = {'\0'};                   //00-80-00-00-00-00-a9-13
    char networkAddress[12] = {'\0'};             //00:00:00:00
    char frequencySubBand = '\0';                 //0-8
    char publicNetwork = '\0';                    //0,1
    uint8_t dataRate = '\0';                      //0-3
    char adaptiveDataRate = '\0';                 //0,1
    float snr = '\0';                             //-00.0 (-20dbm to 20dbm) --> float range: -3.4E38 .. 3.4E38
    int16_t rssi = '\0';                          //-000 (-180dbm to 0dbm) --> int16_t range: -32,768 to 32,767

    AltoviewMDot();                                     //Use default serial port
    AltoviewMDot(uint8_t);                              //Use specified serial port.
    AltoviewMDot(AltSoftSerial*, HardwareSerial*);                      //Use specified serial port and a debugging stream.

    void begin();                                 //Use default baud
    void begin(uint32_t);                         //Use specified baud rate.

    int8_t join();                                //Join a LoRa network.
    int8_t join(uint16_t);                        //Join with a specific timeout
    void leave();                                 //Leave a LoRa network, Not yet implemented

    int8_t send(char*);                           //Generic send command, using AT+SEND
    int8_t send(char*, uint16_t);                 //Use specific timeout.
    int8_t send(char*, uint8_t, uint16_t);        //Use specific message length.
    int8_t sendPairs(String);                     //Takes key,value pairs, forms a message, and sends to the LoRa server.
    int8_t sendPairs(String*);                    //Takes key,value pairs, forms a message, and sends to the LoRa server.
    int8_t sendPairs(char*);                      //Takes key,value pairs, forms a message, and sends to the LoRa server.
    int8_t ping();                                //Uses getSnr() and getRssi(), returns 0 if variables saved, returns -1 if either fncs failed 
    int8_t getSnr();                              //Gets SNR using AT command, returns 0 if variable saved, returns -1 if failed 
    int8_t getRssi();                             //Gets RSSI using AT command, returns 0 if variable saved, returns -1 if failed 

    int8_t setDefaults();
    int8_t setFrequencySubBand(char);
    int8_t getFrequencySubBand();
    int8_t setPublicNetwork(char);
    int8_t getPublicNetwork();
    int8_t setNetworkID(char*);                   //Also referred to as the AppEUI
    int8_t getNetworkID();                        //Also referred to as the AppEUI
    int8_t setNetworkKey(char*);                  //Also referred to as the AppKey
    int8_t getNetworkKey();                       //Also referred to as the AppKey
    int8_t setDataRate(char);
    int8_t setDataRate(uint8_t);
    int8_t getDataRate();
    int8_t setAdaptiveDataRate(char);
    int8_t getAdaptiveDataRate();
    int8_t getDeviceId();
    int8_t getNetworkAddress();
    int8_t getNetworkSessionKey();
    int8_t getDataSessionKey();
    int8_t saveLoraSession();
    int8_t restoreLoraSession();
    int8_t commitSettings();

  private:
    char _txBuffer[_MAX_FRAGMENTS][_PACKET_SIZE];
    uint8_t _txPutter = 0;                        //Number of fragments in buffer. TODO: Replace/rename

    char _response[_MAX_MDOT_RESPONSE];           //mDot response buffer
    uint8_t _length;                              //Lenght of a response

    char _command[_MAX_MDOT_COMMAND];

    int8_t _sendCommand(char*, char*, char*, uint16_t);
    int8_t _sendCommand(char*, char*, char*, uint16_t, char**);   //Generic serial out get response wrapper

    void _pairsToJSON(char*, uint8_t, char*);
    void _createFragmentBuffer(char*);
    int8_t _processBuffer();

    HardwareSerial* _debug_serial;                        //Debugging serial port initialized in constructor
    AltSoftSerial*  _mdot_serial;                         //AT Command serial port selection by user
};

#endif
