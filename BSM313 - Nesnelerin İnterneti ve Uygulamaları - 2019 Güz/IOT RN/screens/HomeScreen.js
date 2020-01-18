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


import { MonoText } from '../components/StyledText';

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
      error: null
     }
   }
   


  componentDidMount() {
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
  const { isLoading, weatherCondition, temperature, city, country } = this.state;
  return (
    <View style={styles.container}>
      <Text style={styles.subText}> OpenWeather API Verisi </Text>
      {isLoading ? (
        <View style={styles.loadingContainer}>
          <Text style={styles.loadingText}>Fetching The Weather</Text>
        </View>
      ) : (
        <Weather weather={weatherCondition} temperature={parseInt((temperature-32)/1.8)} city={city} country={country} />
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
