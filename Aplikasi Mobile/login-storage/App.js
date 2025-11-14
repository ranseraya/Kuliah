import { useState, useEffect } from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import AsyncStorage from '@react-native-async-storage/async-storage';
import RegisterScreen from './screens/RegisterScreen';
import LoginScreen from './screens/LoginScreen';
import HomeScreen from './screens/HomeScreen';
import ProfileScreen from './screens/ProfileScreen';
import OrderScreen from './screens/OrderScreen';
import { Ionicons } from '@expo/vector-icons';

const Stack = createNativeStackNavigator();
const Tab = createBottomTabNavigator();

function MainMenu({ user, setUser }) {
  const InjectedProfileScreen = (props) => (
    <ProfileScreen {...props} user={user} setUser={setUser} />
  );
  return (
    <Tab.Navigator
      screenOptions={({ route }) => ({
        tabBarIcon: ({ focused, color, size }) => {
          let iconName;
          if (route.name === 'Home') {
            iconName = focused ? 'home' : 'home-outline';
          } else if (route.name === 'Orders') {
            iconName = focused ? 'list' : 'list-outline';
          } else if (route.name === 'Profile') {
            iconName = focused ? 'person' : 'person-outline';
          }
          return <Ionicons name={iconName} size={size} color={color} />;
        },
        tabBarActiveTintColor: '#009966',
        tabBarInactiveTintColor: 'gray',
      })}
    >
      <Tab.Screen name="Home">
        {props => <HomeScreen {...props} user={user} />}
      </Tab.Screen>
      <Tab.Screen name="Orders" component={OrderScreen} />
      <Tab.Screen name="Profile" component={InjectedProfileScreen} />
    </Tab.Navigator>
  );
}

export default function App() {
  const [user, setUser] = useState(null);
  const [isLoading, setIsLoading] = useState(true);
  
  const initializeDefaultAdmin = async () => {
    const storedUsers = await AsyncStorage.getItem("users");

    if (!storedUsers) {
      const defaultUser = [
        {
          name: "Administrator",
          email: "admin@mail.com",
          password: "12345",
          npm: "0000"
        }
      ];

      await AsyncStorage.setItem("users", JSON.stringify(defaultUser));
    }
  };

  const checkLoginStatus = async () => {
    try {
      const userString = await AsyncStorage.getItem("user");
      setUser(userString ? JSON.parse(userString) : null);
    } catch (e) {
      console.error("Gagal memuat data user", e);
    }
    setIsLoading(false);
  };

  useEffect(() => {
    initializeDefaultAdmin();
    checkLoginStatus();
  }, []);

  if (isLoading) return null;

  return (
    <NavigationContainer>
      <Stack.Navigator screenOptions={{ headerShown: false }}>

        {user == null ? (
          <>
            <Stack.Screen name="Login">
              {props => <LoginScreen {...props} setUser={setUser} />}
            </Stack.Screen>
            <Stack.Screen name="Register" component={RegisterScreen} />
          </>
        ) : (
          <Stack.Screen name="MainMenu">
            {props => <MainMenu {...props} user={user} setUser={setUser} />}
          </Stack.Screen>
        )}

      </Stack.Navigator>
    </NavigationContainer>
  );
}