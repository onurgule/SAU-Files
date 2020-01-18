import * as WebBrowser from 'expo-web-browser';
import React from "react";
import {
  Image,
  Platform,
  ScrollView,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,

} from 'react-native';
import Weather from '../components/Weather';
import { API_KEY } from '../utils/WeatherAPIKey';
import { weatherConditions } from '../utils/WeatherConditions';




import { MonoText } from '../components/StyledText';
import {firebaseConfig} from '../config.js'
var firebase = require("firebase");
if (!firebase.apps.length) {
  firebase.initializeApp(firebaseConfig);
}



export default class LinkScreen extends React.Component {
  constructor(props)
   {
     super(props);
     this.state={
      isLoading: true,
      temperature: 0,
      weatherCondition: null,
      city: "ISTANBUL",
      country: "TR",
      error: null,
      fbsicaklik:0,
     }
   }


  componentDidMount() {
    const component = this;
    firebase.database().ref('Olcumler').limitToLast(1).once('child_added', function(childSnapshot) {
       var snap = childSnapshot.val();
       console.log(snap);
       if(snap.sicaklik != undefined)
       component.setState({ fbsicaklik:snap.sicaklik.toFixed(2)});
       if(snap.timestamp != undefined)
       component.setState({ time:snap.timestamp});
    });
    firebase.database().ref('Olcumler').limitToLast(1).on('child_changed', function(childSnapshot) {
       var snap = childSnapshot.val();
       console.log(snap);
       if(snap.sicaklik != undefined)
       component.setState({ fbsicaklik:snap.sicaklik.toFixed(2)});
       if(snap.timestamp != undefined)
       component.setState({ time:snap.timestamp});
    });
    navigator.geolocation.getCurrentPosition(
      position => {
        this.fetchWeather(position.coords.latitude, position.coords.longitude);
      },
      error => {
        this.setState({
          error: 'Error Getting Weather Condtions'
        });
      }
    );

   /* firebase.database().ref('guncelSicaklik/').once('value', function (snapshot) {
      var havasicakmifb = (snapshot.val());
      this.setState({ fbsicaklik:havasicakmifb});
  }.bind(this));
  */

}
last10avg(){
  var son10ort = 0;

  var ref = firebase.database().ref('Olcumler');
  ref.limitToLast(10).on("child_added", function(snapshot) {
    var snap = snapshot.val();
    son10ort += snap.sicaklik;
});
son10ort = son10ort/10;
return son10ort;
}

  fetchWeather(lat, lon) {
    fetch(
      `http://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&APPID=${API_KEY}&units=imperial`
    )
      .then(res => res.json())
      .then(json => {
        // console.log(json);
        this.setState({
          temperature: Math.round(json.main.temp),
          weatherCondition: json.weather[0].main,
          city: json.name,
          country: json.sys.country,
          isLoading: false
        });
      });


  }


render() {

  const { isLoading, weatherCondition, temperature, city, country,fbsicaklik } = this.state;
  return (
    <View style={styles.container}>
      <Text style={styles.subText}> LM35 Verisi = {this.state.fbsicaklik} Celcius</Text>
      {isLoading ? (
        <View style={styles.loadingContainer}>
          <Text style={styles.loadingText}>LM35 verisi yükleniyor...</Text>
        </View>
      ) : (


        <Weather weather={weatherCondition} temperature={this.last10avg().toFixed(2)} country={country} time={this.state.time} />

      )}
    </View>
  );
}
}

LinkScreen.navigationOptions = {
  header: null,
};

const styles = StyleSheet.create({
container: {
  flex: 1,
  backgroundColor: '#fff'
},
loadingContainer: {
  flex: 1,
  alignItems: 'center',
  justifyContent: 'center',
  backgroundColor: '#FFFDE4'
},
loadingText: {
  fontSize: 30
},
subText: {
  fontSize: 28,
  color: 'white',
  paddingTop:30,
  backgroundColor: '#005BEA'
},
});
