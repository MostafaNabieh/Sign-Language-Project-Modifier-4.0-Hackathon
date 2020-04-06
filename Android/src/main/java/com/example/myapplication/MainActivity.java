package com.example.myapplication;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.ahmedabdelmeged.bluetoothmc.BluetoothMC;
import com.ahmedabdelmeged.bluetoothmc.ui.BluetoothDevices;
import com.ahmedabdelmeged.bluetoothmc.util.BluetoothStates;
import com.ahmedabdelmeged.bluetoothmc.util.InputDataHelper;

import java.util.ArrayList;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {
    String text;
    BluetoothMC bluetoothMC;
    InputDataHelper inputDataHelper;
    ArrayList<String> sensors;
    TextToSpeech tts;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bluetoothMC = new BluetoothMC();
        inputDataHelper = new InputDataHelper();
        sensors=new ArrayList<>();
        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!bluetoothMC.isBluetoothAvailable()) {
                    //do any action if the bluetooth is not available
                    Toast.makeText(MainActivity.this, "No any Arduino Available", Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Toast.makeText(MainActivity.this, "There Arduino Available", Toast.LENGTH_SHORT).show();

                }
            }
        });
        //check if the bluetooth is now available
        Button button2 = findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!bluetoothMC.isBluetoothEnabled()) {
                    Toast.makeText(MainActivity.this, "Please Enable Your Bluetooth", Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Toast.makeText(MainActivity.this, "your Bluetooth Enable ", Toast.LENGTH_SHORT).show();

                }
            }

        });

        final Button button3 = findViewById(R.id.button3);
        final Button bu_speech = findViewById(R.id.bu_speech);

        final Button button4 = findViewById(R.id.button4);
        final Button button5 = findViewById(R.id.button5);
        button5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (bluetoothMC.isBluetoothEnabled() && bluetoothMC.isBluetoothAvailable()) {
                    button3.setEnabled(true);
                    button4.setEnabled(true);
                }
                else {
                    button3.setEnabled(false);
                    button4.setEnabled(false);
                }
            }
        });
        button3.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {


                        Intent intent = new Intent(MainActivity.this, BluetoothDevices.class);
                        startActivityForResult(intent, BluetoothStates.REQUEST_CONNECT_DEVICE);
                        bluetoothMC.setOnBluetoothConnectionListener(new BluetoothMC.BluetoothConnectionListener() {
                            @Override
                            public void onDeviceConnecting() {
                                //this method triggered during the connection processes
                                Toast.makeText(MainActivity.this, "Device Connecting", Toast.LENGTH_SHORT).show();

                            }

                            @Override
                            public void onDeviceConnected() {
                                //this method triggered if the connection success
                                Toast.makeText(MainActivity.this, "Device Connected", Toast.LENGTH_SHORT).show();

                            }

                            @Override
                            public void onDeviceDisconnected() {
                                //this method triggered if the device disconnected
                                Toast.makeText(MainActivity.this, "Device disconnected", Toast.LENGTH_SHORT).show();

                            }

                            @Override
                            public void onDeviceConnectionFailed() {
                                //this method triggered if the connection failed
                                Toast.makeText(MainActivity.this, "Connection failed try again", Toast.LENGTH_SHORT).show();

                            }
                        });
                    }
                });



        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bluetoothMC.setOnDataReceivedListener(new BluetoothMC.onDataReceivedListener() {
                    @Override
                    public void onDataReceived(String data) {
                        sensors = inputDataHelper.setSensorsValues(data);
                        TextView textView=findViewById(R.id.textView);
                        textView.setText(sensors.toString()+"");
                        bu_speech.setEnabled(true);
                        bu_speech.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                tts=new TextToSpeech(MainActivity.this, new TextToSpeech.OnInitListener() {

                                    @Override
                                    public void onInit(int status) {
                                        if(status == TextToSpeech.SUCCESS){
                                            int result=tts.setLanguage(Locale.US);
                                            if(result==TextToSpeech.LANG_MISSING_DATA ||
                                                    result==TextToSpeech.LANG_NOT_SUPPORTED){
                                                Log.e("error", "This Language is not supported");
                                            }
                                            else{
                                                ConvertTextToSpeech(sensors.toString());
                                            }
                                        }
                                        else
                                            Log.e("error", "Initilization Failed!");
                            }
                        });

                            }
                        });


                    }
                });
            }
        });

        bluetoothMC.setOnBluetoothErrorsListener(new BluetoothMC.BluetoothErrorsListener() {
            @Override
            public void onSendingFailed() {
                //this method triggered if the app failed to send data
                showToast("Send data failed");

            }

            @Override
            public void onReceivingFailed() {
                //this method triggered if the app failed to receive data
                showToast("Receive data failed");

            }

            @Override
            public void onDisconnectingFailed() {
                //this method triggered if the app failed to disconnect to the bluetooth device
                showToast("Can't disconnect");

            }

            @Override
            public void onCommunicationFailed() {
                //this method triggered if the app connect and unable to send and receive data
                //from the bluetooth device
                showToast("Communication failed try again");

            }
        });

    }
    private void showToast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == BluetoothStates.REQUEST_CONNECT_DEVICE) {
            if (resultCode == Activity.RESULT_OK) {
                try {
                    assert data != null;
                    bluetoothMC.connect(data);
                } catch (Exception ex) {
                    {
                        Toast.makeText(MainActivity.this, "Error Connect", Toast.LENGTH_SHORT).show();
                    }


                }
            }
        }
    }
    @Override
    protected void onPause() {

        if(tts != null){

            tts.stop();
            tts.shutdown();
        }
        super.onPause();
    }
    private void ConvertTextToSpeech(String text) {
        if(text==null||"".equals(text))
        {
            text = "Content not available";
            tts.speak(text, TextToSpeech.QUEUE_FLUSH, null);
        }else
            tts.speak(text+"is saved", TextToSpeech.QUEUE_FLUSH, null);
    }
}
