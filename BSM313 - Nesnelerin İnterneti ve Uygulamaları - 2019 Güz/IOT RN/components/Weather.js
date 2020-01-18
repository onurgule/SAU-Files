import React from 'react';
import { View, Text, StyleSheet } from 'react-native';
import { MaterialCommunityIcons } from '@expo/vector-icons';
import PropTypes from 'prop-types';
import { weatherConditions } from '../utils/WeatherConditions';

const Weather = ({ weather, temperature, city, country, time="", lat="", lon="" }) => {
if(time != ""){
var timedate = new Date(time);
var strTime = timedate.getHours() + ":" + timedate.getMinutes() + ":" + timedate.getSeconds();
}
  return (
    <View
      style={[
        styles.weatherContainer,
        { backgroundColor: weatherConditions[weather].color }
      ]}
    >

      <View style={styles.headerContainer}>
        <MaterialCommunityIcons
          size={70}
          name={weatherConditions[weather].icon}
          color={'#fff'}
        />

        <Text style={styles.tempText}>{temperature }˚C</Text>
      </View>
      <View style={styles.subHeaderContainer}>
      {(city != undefined) &&
        <Text style={styles.subText}>{city}</Text>
      }
      {(city == undefined) &&
        <Text style={styles.subText}>Bulunduğunuz konum</Text>
      }
        {(strTime != undefined) &&
        <Text style={styles.subText}>Veri Zamanı: {strTime}</Text>
        }
      </View>
      <View style={styles.bodyContainer}>
        <Text style={styles.title}>{weatherConditions[weather].title}</Text>
        <Text style={styles.subtitle}>
          {weatherConditions[weather].subtitle}
        </Text>
      </View>
    </View>
  );
};

Weather.propTypes = {
  temperature: PropTypes.number.isRequired,
  weather: PropTypes.string
};

const styles = StyleSheet.create({
  weatherContainer: {
    flex: 1
  },
  headerContainer: {
    flex: 1,
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'flex-start',
    paddingLeft: 20,
    paddingTop: 40,
    paddingBottom: 0
  },
  subHeaderContainer: {
    flex: 1,
    alignItems: 'flex-start',
    justifyContent: 'flex-start',
    paddingLeft: 25,
    paddingTop: 0
  },
  tempText: {
    fontSize: 60,
    color: '#fff',
    paddingLeft: 10
  },
  subText: {
    fontSize: 28,
    color: '#fff'
  },
  baslikText: {
    fontSize: 28,
    color: '#fff',
    paddingTop:30,
    fontWeight:"bold"
  },
  bodyContainer: {
    flex: 2,
    alignItems: 'flex-start',
    justifyContent: 'flex-end',
    paddingLeft: 25,
    paddingRight: 10,
    marginBottom: 40
  },
  title: {
    fontSize: 60,
    color: '#fff'
  },
  subtitle: {
    fontSize: 24,
    color: '#fff'
  }
});

export default Weather;
