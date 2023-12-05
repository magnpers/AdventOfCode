Console.WriteLine("Starting app!");

string dayNr = "1";

StreamWriter dataFileStream = null, logFileStream = null;

string curentDir = $"{Directory.GetCurrentDirectory()}";
string ProjFolder = $"{Directory.GetParent(curentDir).Parent.Parent.Parent}\\";
try
{
    //Create a dope log file
    SetLogFileStream(dayNr);

    Log("Daily log file stream set");

    //Fetch input data
    string data = await FetchAocData(dayNr);

    Log("Daily input data fetched");

    //Open read for data file
    SetDataFileStream(dayNr);

    Log("Daily data file stream set");

    //Write data to data file
    WriteDailyDataToFile(data);

    Log("Daily data written to file");

    //Close write to data file
    dataFileStream.Close();

    Log("Closed data file stream");

    //Closre write to log file
    Log("Closing log file..");

    logFileStream.Close();
}
catch (Exception ex)
{
    Console.WriteLine(ex.ToString());
    if (logFileStream != null)
        Log(ex.ToString());
    throw;
}
finally
{
    if (dataFileStream != null)
        dataFileStream.Close();

    if (logFileStream != null)
        logFileStream.Close();

}

void WriteDailyDataToFile(string data)
{
    dataFileStream.Write(data);
    dataFileStream.Flush();
}

void SetLogFileStream(string dayNr)
{
    try
    {
        Console.WriteLine("Creating log file");

        string logFolder = $"{ProjFolder + "Logs\\"}";
        if (Directory.Exists(logFolder) == false)
            Directory.CreateDirectory(logFolder);

        string dayFilePath = $"{logFolder + "Log"} {dayNr}.txt";

        if (File.Exists(dayFilePath) == true)
        {
            logFileStream = new StreamWriter(dayFilePath);
            Log("----------------");
        }
        else
            logFileStream = new StreamWriter(File.Create(dayFilePath));

        if (logFileStream == null)
            throw new Exception("Log file streram is still null!");
    }
    catch (Exception)
    {
        throw;
    }
}

void SetDataFileStream(string dayNr)
{
    try
    {
        string dataFolder = $"{ProjFolder + "Data\\"}";
        if (Directory.Exists(dataFolder) == false)
            Directory.CreateDirectory(dataFolder);

        string dayFilePath = $"{dataFolder + "Day"}{dayNr}.txt";

        if (File.Exists(dayFilePath) == true)
            File.Delete(dayFilePath);

        dataFileStream = new StreamWriter(File.Create(dayFilePath));

        if (dataFileStream == null)
            throw new Exception("Data file streram is still null!");
    }
    catch (Exception)
    {
        throw;
    }
}

async Task<string> FetchAocData(string dayNr)
{
    try
    {
        Uri reqeustUrl = new Uri($"https://adventofcode.com/2023/day/{dayNr}/input");

        string requestCookie = "";

        var httpClient = new HttpClient();

        HttpRequestMessage message = new HttpRequestMessage(HttpMethod.Get, reqeustUrl);

        message.Headers.Add("Cookie", requestCookie);

        var response = await httpClient.SendAsync(message);

        if (response.IsSuccessStatusCode == true)
        {
            return await response.Content.ReadAsStringAsync();
        }
        else
            throw new Exception($"Failed to fetch daily data\n" +
                $"ResponseCode: {(int)response.StatusCode}{response.StatusCode}" +
                $"ReasonPhrase: {response.ReasonPhrase}");
    }
    catch (Exception)
    {
        throw;
    }
}

void Log(string logString)
{
    try
    {
        if (logFileStream == null)
            throw new Exception("logFileStream cannot be null");

        string timestamp = DateTime.Now.ToString("yyyy-MM-ddTHH:mm:ss:f");

        logFileStream.WriteLine($"{logString}\t\t{timestamp}");

        logFileStream.Flush();
    }
    catch (Exception)
    {
        throw;
    }
}