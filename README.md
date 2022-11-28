# MogreSocks  
C++/CLI Wrapper for OgreSocks use for MOGRE

## CLR Version  
.NET Framework 3.5  

## Environment 
Visual Studio 2008  
Windows 7 VM (Virtual Box 6.1.3)

## Usage  

### Initialise
```
MogreSocksManager.Instance.Initialise();
```

### Create MogreSocks Object
```
MogreSocksTCPClient msocket = null;
MogreSocksManager.Instance.CreateSocket(ref msocket);
```

### Event Process
```
ConnectListener connectlistener = new ConnectionListener();
connectListener.OnConnect += YourConnectEventHandler;
mscocket.SetConnectionListener(connectlistener);
```

### Dispose
```
MogreSocksManager.Instance.DeleteSocket(msocket);
MogreSocksManager.Instance.Cleanup();
```

## License
GNU GPLv3
