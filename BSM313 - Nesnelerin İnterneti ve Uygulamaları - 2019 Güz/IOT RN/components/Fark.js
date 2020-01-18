import React from 'react';
import { View, Text, StyleSheet, Dimensions } from 'react-native';
import { MaterialCommunityIcons } from '@expo/vector-icons';
import PropTypes from 'prop-types';
import { weatherConditions } from '../utils/WeatherConditions';
var nwidth = Dimensions.get('screen').width;
const Fark = ({ weather, temperature, city, country, time="", lat="", lon="", gelecek,fbsicaklik }) => {
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
      {(temperature >= 0) &&
        <View>
        <Text style={styles.tempText}>{temperature.toFixed(2) }˚C</Text>
        <Text style={styles.subText}>Daha soğuk</Text>
        </View>
      }
      {(temperature < 0) &&
        <View>
        <Text style={styles.tempText}>{(-1)*(temperature.toFixed(2)) }˚C</Text>
        <Text style={styles.subText}>Daha sıcak</Text>
        </View>
      }

      </View>
      <View style={styles.subHeaderContainer}>
        <Text style={styles.subText}>Hesaplanan ve Ölçülen Sıcaklık farkı</Text>
        {(strTime != undefined) &&
        <Text style={styles.subText}>Veri Zamanı: {strTime}</Text>
        }
        <Text style={[styles.subText, {marginTop:25, textAlign: 'center', marginLeft: 85}]}>Tahminler</Text>
      </View>
{(gelecek != undefined) &&
      <View style={[styles.subHeaderContainer,{flexDirection: 'row', marginTop:80}]}>
      <View style={{width:nwidth*0.3}}>

        <Text style={styles.subText}>{(gelecek.list[0].main.temp + ((temperature>0)?temperature:temperature*-1)).toFixed(2)} ˚C</Text>
        <Text style={styles.subText}>{gelecek.list[0].dt_txt.substr(11).substr(0,5)}</Text>
      </View>
      <View style={{width:nwidth*0.3}}>
        <Text style={styles.subText}>{(gelecek.list[1].main.temp + ((temperature>0)?temperature:temperature*-1)).toFixed(2)} ˚C</Text>
        <Text style={styles.subText}>{gelecek.list[1].dt_txt.substr(11).substr(0,5)}</Text>
        </View>
        <View style={{width:nwidth*0.3}}>
        <Text style={styles.subText}>{(gelecek.list[2].main.temp + ((temperature>0)?temperature:temperature*-1)).toFixed(2)} ˚C</Text>
        <Text style={styles.subText}>{gelecek.list[2].dt_txt.substr(11).substr(0,5)}</Text>
        </View>
      </View>
    }
      <View style={styles.bodyContainer}>
      </View>
    </View>
  );
};

Fark.propTypes = {
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
    paddingTop: 35
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

export default Fark;
