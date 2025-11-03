import React, { Component } from 'react';

import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';

import Home from './src/screens/Home';
import SplashScreen from './src/screens/SplashScreen';
import About from './src/screens/About';
import Projects from './src/screens/Projects';
import Contact from './src/screens/Contact';

const Stack = createNativeStackNavigator();

function App(){
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName='SplashScreen' screenOptions={{headerShown: false }}>
        <Stack.Screen name="SplashScreen" component={SplashScreen} />
        <Stack.Screen name="Home" component={Home} />
        <Stack.Screen name="AboutMe" component={About} />
        <Stack.Screen name="Projects" component={Projects} />
        <Stack.Screen name="ContactMe" component={Contact} />
      </Stack.Navigator>
    </NavigationContainer>
  )
}

export default App;