import React from 'react';
import { View, Text, TouchableOpacity } from 'react-native';

const Detail = () => {
    return (
        <View>
            <Text>Detail</Text>
            <TouchableOpacity onPress={() => {navigation.navigate('Detail')}}>
                <Text>Pindah Screen </Text>
            </TouchableOpacity>
        </View>
    )
}

export default Detail;