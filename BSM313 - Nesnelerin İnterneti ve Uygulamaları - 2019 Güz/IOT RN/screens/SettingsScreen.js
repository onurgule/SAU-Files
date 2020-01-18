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
import Fark from '../components/Fark';
import { API_KEY } from '../utils/WeatherAPIKey';


import { MonoText } from '../components/StyledText';
import {firebaseConfig} from '../config.js'
var firebase = require("firebase");
if (!firebase.apps.length) {
  firebase.initializeApp(firebaseConfig);
}
export default class HomeScreen extends React.Component {
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
      gelecek:[],
     }
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

tahmin(){
  fetch("https://api.openweathermap.org/data/2.5/forecast?lat=40.742264&lon=30.325671&lang=tr&cnt=3&units=metric&appid=51a199c3f6738edfb74cfca15c01061f")
  .then(res => res.json())
  .then(json => {
    console.log(json);
    this.setState({gelecek:json});
  });
}

  componentDidMount() {
    const component = this;

    console.log("ooo:" + this.last10avg());
    firebase.database().ref('Olcumler').limitToLast(1).once('child_added', function(childSnapshot) {
       var snap = childSnapshot.val();
       console.log(snap);
       if(snap.sicaklik != undefined)
       component.setState({ fbsicaklik:component.last10avg().toFixed(2)});
       if(snap.timestamp != undefined)
       component.setState({ time:snap.timestamp});
    });
    firebase.database().ref('Olcumler').limitToLast(1).on('child_changed', function(childSnapshot) {
      //değiştiğinde yapılacaklar...
       var snap = childSnapshot.val();
       if(snap.sicaklik != undefined)
       component.setState({ fbsicaklik:component.last10avg().toFixed(2)});
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
      });
      this.tahmin();
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
  //https://api.openweathermap.org/data/2.5/forecast?lat=40.742264&lon=30.325671&cnt=3&units=metric&appid=51a199c3f6738edfb74cfca15c01061f
  //SON 3 gelecek data.
render() {
  const { isLoading, weatherCondition, temperature, city, country,fbsicaklik,gelecek } = this.state;
  return (
    <View style={styles.container}>
      <Text style={styles.subText}> Tahmin </Text>
      {isLoading ? (
        <View style={styles.loadingContainer}>
          <Text style={styles.loadingText}>Fetching The Weather</Text>
        </View>
      ) : (
        <Fark weather={weatherCondition} gelecek={gelecek} fbsicaklik={fbsicaklik} temperature={(((temperature-32)/1.8)-fbsicaklik)} city={city} time={this.state.time} country={country} />
      )}
    </View>
  );
}
}

HomeScreen.navigationOptions = {
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
